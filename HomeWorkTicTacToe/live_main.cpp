#include <iostream>
#include <random>
      // в основном ничего не менял, добавил функцию YouChoisSize для возможности играть на поле разного размера, ограничился полем 20х20.
     /* 84 строка, создал динамический массив для Ai, там же его и удалил, но не понял откуда удалить массив в структуре.
        Если удалить в функции runGameLoop, то коректно отработает только один кон игры. поэтому оставил его до закрытия программы.*/
   // 121 строка, на сколько я понял был нарушен порядок "%" и "/", поэтому при ходе, Ai перезатирал клетки, так как собирал индекс пустых клеток по другому.
  //146 строка, изменил функцию IsDraw
 //183 строка , проверка на выигрыш для произвольного поляю.
// 185 строка, добавил что если "ничья" то игра окончена.



enum class CellState {
    Empty, X, O
};

enum class Sign {
    X, O
};

struct GameField {
    int sizeBoard = 20;
    CellState *cells = new CellState[sizeBoard * sizeBoard];
};

struct GameData {
    GameField field;
    Sign player_sign;
};

struct TurnOutcome {
    bool isOver : 1;
    Sign victor : 1;
    bool isDraw : 1;
};
int YouChoisSize(){
    int size;
    std::cout << "Enter size board\n";
    std::cin >> size;
    while(size < 3 || size > 20){
        std::cout << "Wrong enter number, please enter 1 - 20\n";
        std::cin >> size;
    }

    return size;

}
bool isValidCell(GameField field, size_t row, size_t column) {
    return row >= 0 && row < field.sizeBoard && column >= 0 && column < field.sizeBoard;
}

CellState getCell(const GameField& field, size_t row, size_t column) {
    if (!isValidCell(field, row, column)) return CellState::Empty;
    return field.cells[column * field.sizeBoard + row];
}

bool isCellEmpty(const GameField& field, size_t row, size_t column) {
    return getCell(field, row, column) == CellState::Empty;
}

void putSign(GameField& field, Sign sign, size_t row, size_t column) {
    if (isValidCell(field ,row, column)) {
        field.cells[column * field.sizeBoard + row] = (sign == Sign::X) ? CellState::X : CellState::O;
    }
}

bool askQuestion(char positive, char negative) {
    char sign {};
    std::cin >> sign;
    sign = tolower(sign);

    while (sign != positive && sign != negative) {
        std::cout << "Wrong input: received '" << sign << "', should be one of " << positive << " or " << negative << "\n";
        std::cin >> sign;
        sign = tolower(sign);
    }
    return sign == positive;
}

Sign queryPlayerSign() {
    std::cout << "Please input wheter you're X or O: ";
    bool isX = askQuestion('x', 'o');
    return isX ? Sign::X : Sign::O;
}

TurnOutcome checkTurnOutcome(const GameField& field);

void processAiTurn(GameField& field, Sign ai_sign) {
    size_t *empty_cells = new size_t[field.sizeBoard * field.sizeBoard] ;
    const size_t kInvalidCellIdx = 42;
    std::fill_n(empty_cells, field.sizeBoard, kInvalidCellIdx);
    size_t last_empty_cell_idx = 0;
    for (size_t i = 0; i < (field.sizeBoard * field.sizeBoard); i++) {
        if (field.cells[i] == CellState::Empty) {
            empty_cells[last_empty_cell_idx] = i;
            last_empty_cell_idx++;
        }
    }

    static std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_int_distribution<size_t> dist(0, last_empty_cell_idx - 1);

    for (size_t i = 0; i < last_empty_cell_idx; i++) {
        size_t target = empty_cells[i];
        field.cells[target] = ai_sign == Sign::X ? CellState::X : CellState::O;
        auto outcome = checkTurnOutcome(field);
        if (outcome.isOver) {
            return;
        }
        field.cells[target] = CellState::Empty;

        auto opposite_sign = ai_sign == Sign::X ? Sign::O : Sign::X;
        field.cells[target] = opposite_sign == Sign::X ? CellState::X : CellState::O;
        outcome = checkTurnOutcome(field);
        if (outcome.isOver) {
            field.cells[target] = ai_sign == Sign::X ? CellState::X : CellState::O;
            return;
        }
        field.cells[target] = CellState::Empty;
    }
    size_t target = empty_cells[dist(mt)];
    putSign(field, ai_sign, target % field.sizeBoard, target / field.sizeBoard);
    delete [] empty_cells;

}

void processPlayerTurn(GameField& field, Sign player_sign) {
    std::cout << "Enter row and column: ";

    int row, column;
    std::cin >> row >> column;

    while (!isValidCell(field,row - 1, column - 1) || !isCellEmpty(field, row - 1, column - 1)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong input, please enter row and column of an empty cell: ";
        std::cin >> row >> column;
    }

    putSign(field, player_sign, row - 1, column - 1);
}

void printField(const GameField& field);

bool isDraw(const GameField& field) {
    for (size_t i = 0; i < (field.sizeBoard * field.sizeBoard); i++) {
        if (field.cells[i] == CellState::Empty) {
            return false;
        }
    }
    return true;
}

bool checkLine(const GameField& field, size_t start_row, size_t start_column, int delta_row, int delta_column) {
    size_t current_row = start_row;
    size_t current_column = start_column;
    auto first = getCell(field, start_row, start_column);
    if (first == CellState::Empty) {
        return false;
    }
    while (isValidCell(field,current_row, current_column)) {
        if (getCell(field, current_row, current_column) != first) {
            return false;
        }
        current_row += delta_row;
        current_column += delta_column;
    }
    return true;
}

#define CHECK_LINE(start_row, start_column, delta_row, delta_column) \
        if (checkLine(field, start_row, start_column, delta_row, delta_column)) { \
            outcome.isOver = true; \
            outcome.victor = getCell(field, start_row, start_column) == CellState::X ? Sign::X : Sign::O; \
            return outcome; \
        }


TurnOutcome checkTurnOutcome(const GameField& field) {
    TurnOutcome outcome {};
    for (size_t row = 0; row < field.sizeBoard; row++) {
        CHECK_LINE(row, 0, 0, 1)
    }
    for (size_t column = 0; column < field.sizeBoard; column++) {
        CHECK_LINE(0, column, 1, 0)
    }
    CHECK_LINE(0, 0, 1, 1)
    CHECK_LINE(0, (field.sizeBoard - 1), 1, -1)

    if (isDraw(field)) {
        outcome.isDraw = true;
        outcome.isOver = true;
    }
    return outcome;
}

#undef CHECK_LINE

TurnOutcome runGameLoop(Sign player_sign) {

    GameData game_data;
    TurnOutcome outcome {};
    game_data.field.sizeBoard = YouChoisSize();
    while(true) {
        if(player_sign == Sign::X) {
            processPlayerTurn(game_data.field, Sign::X);
        } else {
            processAiTurn(game_data.field, Sign::X);
        }

        printField(game_data.field);
        outcome = checkTurnOutcome(game_data.field);
        if (outcome.isOver) {

            return outcome;
        }

        if(player_sign == Sign::O) {
            processPlayerTurn(game_data.field, Sign::O);
        } else {
            processAiTurn(game_data.field, Sign::O);
        }

        printField(game_data.field);
        outcome = checkTurnOutcome(game_data.field);
        if (outcome.isOver) {

            return outcome;
        }
    }
}

void printField(const GameField& field) {

    std::cout << "\n ";
    int i = 0;

    while (i < ((field.sizeBoard + 1)+ (field.sizeBoard))) {
        std::cout << '=';
        i++;

    }
    std::cout << '\n';
    for (size_t row = 0; row < field.sizeBoard; row++) {
        std::cout << "||";
        for (size_t column = 0; column < field.sizeBoard; column++) {

            switch (getCell(field, row, column))
            {
            case CellState::Empty:
                std::cout << " ";
                break;
            case CellState::X:
                std::cout << "X";
                break;
            case CellState::O:
                std::cout << "O";
                break;
            }
            std::cout << "|";
        }
        std::cout << "|\n";
    }
    int y = 0;
    std::cout << ' ';
    while (y < ((field.sizeBoard + 1)+ (field.sizeBoard))) {
        std::cout << '=';
        y++;

    }
}

bool queryPlayAgain() {
    std::cout << "Want to play again? [y or n]: ";
    return askQuestion('y', 'n');
}

void printGameOutcome(const TurnOutcome& outcome, Sign player_sign) {
    if (outcome.isDraw) {
        std::cout << "\nIt's a draw.\n";
    } else if (outcome.victor == player_sign) {
        std::cout << "\nCongrats! You're winner.\n";
    } else {
        std::cout << "\nNo luck this time.\n";
    }
}

int main() {
    Sign player_sign = queryPlayerSign();

    bool shouldExit = false;
    while(!shouldExit) {
        auto outcome = runGameLoop(player_sign);
        printGameOutcome(outcome, player_sign);
        shouldExit = !queryPlayAgain();


    }

    return 0;
}
