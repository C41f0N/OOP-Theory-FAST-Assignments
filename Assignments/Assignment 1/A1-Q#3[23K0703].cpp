#include <iostream>
#include <cmath>

using namespace std;

class ChessPiece
{
    string name;
    string color;
    char symbol;

public:
    ChessPiece()
    {
        color = "white";
        name = "pawn";
        symbol = 'p';
    }

    ChessPiece(string color, string name, char symbol)
    {
        this->color = color;
        this->name = name;
        this->symbol = symbol;
    }

    string getColor()
    {
        return color;
    }

    void setColor(string color)
    {
        if (color == "white" || color == "black")
        {
            this->color = color;
        }
    }

    string getName()
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    char getSymbol()
    {
        return symbol;
    }

    void setSymbol(char symbol)
    {
        this->symbol = symbol;
    }
};

class ChessBoard
{
    ChessPiece ***board;

public:
    ChessBoard()
    {
        // Setting up the board structure
        board = new ChessPiece **[8];
        for (int i = 0; i < 8; i++)
        {
            board[i] = new ChessPiece *[8];
            for (int j = 0; j < 8; j++)
            {
                board[i][j] = nullptr;
            }
        }

        // Setting up pieces on inital positions
        // Row 8
        board[7][0] = new ChessPiece("black", "Rook", 'R');
        board[7][1] = new ChessPiece("black", "Knight", 'N');
        board[7][2] = new ChessPiece("black", "Bishop", 'B');
        board[7][3] = new ChessPiece("black", "Queen", 'Q');
        board[7][4] = new ChessPiece("black", "King", 'K');
        board[7][5] = new ChessPiece("black", "Bishop", 'B');
        board[7][6] = new ChessPiece("black", "Knight", 'N');
        board[7][7] = new ChessPiece("black", "Rook", 'R');

        // Row 7
        board[6][0] = new ChessPiece("black", "Pawn", 'P');
        board[6][1] = new ChessPiece("black", "Pawn", 'P');
        board[6][2] = new ChessPiece("black", "Pawn", 'P');
        board[6][3] = new ChessPiece("black", "Pawn", 'P');
        board[6][4] = new ChessPiece("black", "Pawn", 'P');
        board[6][5] = new ChessPiece("black", "Pawn", 'P');
        board[6][6] = new ChessPiece("black", "Pawn", 'P');
        board[6][7] = new ChessPiece("black", "Pawn", 'P');

        // Row 2
        board[1][0] = new ChessPiece();
        board[1][1] = new ChessPiece();
        board[1][2] = new ChessPiece();
        board[1][3] = new ChessPiece();
        board[1][4] = new ChessPiece();
        board[1][5] = new ChessPiece();
        board[1][6] = new ChessPiece();
        board[1][7] = new ChessPiece();

        // Row 1
        board[0][0] = new ChessPiece("white", "Rook", 'r');
        board[0][1] = new ChessPiece("white", "Knight", 'n');
        board[0][2] = new ChessPiece("white", "Bishop", 'b');
        board[0][4] = new ChessPiece("white", "King", 'k');
        board[0][3] = new ChessPiece("white", "Queen", 'q');
        board[0][5] = new ChessPiece("white", "Bishop", 'b');
        board[0][6] = new ChessPiece("white", "Knight", 'n');
        board[0][7] = new ChessPiece("white", "Rook", 'r');
    }

    bool movePiece(string source, string destination)
    {

        // calculate position indexes
        char colAlphSrc = source[0];
        char rowNumSrc = source[1];

        char colAlphDst = destination[0];
        char rowNumDst = destination[1];

        // convert alphabet colNum to array index
        int colIndexSrc = colAlphSrc - 'a';
        int colIndexDst = colAlphDst - 'a';

        // convert number rowNumSrc to array's index
        int rowIndexSrc = (rowNumSrc - '0') - 1;
        int rowIndexDst = (rowNumDst - '0') - 1;

        // Check if source and destination are within bounds
        if (rowIndexDst > 8 || rowIndexDst < 0 || rowIndexSrc > 8 || rowIndexSrc < 0 || colIndexDst > 8 || colIndexDst < 0 || colIndexSrc > 8 || colIndexSrc < 0)
        {
            return false;
        }

        // Check if space is available on the destination and source has a piece
        if (board[rowIndexSrc][colIndexSrc] == nullptr || board[rowIndexDst][colIndexDst] != nullptr)
        {
            return false;
        }

        // Knights
        if ((*board[rowIndexSrc][colIndexSrc]).getName() == "Knight")
        {
            // Calculating vertical and horizontal distances
            int deltaHorizontal = abs(rowIndexSrc - rowIndexDst);
            int deltaVertical = abs(colIndexSrc - colIndexDst);

            // either verical distance should be 2 and the horizontal 1, or vice versa,
            // both cannot be the same, or any other number

            if (!((deltaHorizontal == 2 || deltaHorizontal == 1) && (deltaVertical == 2 || deltaVertical == 1)) && (deltaHorizontal != deltaVertical))
            {
                return false;
            }

            // if no checks are triggered, initiate the move

            // Assigning the source piece to destination, and clearing the source piece
            board[rowIndexDst][colIndexDst] = board[rowIndexSrc][colIndexSrc];
            board[rowIndexSrc][colIndexSrc] = nullptr;

            return true;
        }

        // Black Pawns
        if ((*board[rowIndexSrc][colIndexSrc]).getSymbol() == 'P')
        {
            // Calculating vertical and horizontal distances
            int deltaHorizontal = rowIndexDst - rowIndexSrc;
            int deltaVertical = colIndexDst - colIndexSrc;

            // horizontal distance should be 0, vertical distance should be -1 or -2, if the row is 7

            // Check if initial position
            if (rowIndexSrc == 6)
            {
                if (!(deltaVertical == 0 && (deltaHorizontal == -2 || deltaHorizontal == -1)))
                {
                    return false;
                }
            }
            else
            {
                if (!(deltaVertical == 0 && deltaHorizontal == -1))
                {
                    return false;
                }
            }

            // if no checks are triggered, initiate the move

            // Assigning the source piece to destination, and clearing the source piece
            board[rowIndexDst][colIndexDst] = board[rowIndexSrc][colIndexSrc];
            board[rowIndexSrc][colIndexSrc] = nullptr;

            return true;
        }

        // White Pawns
        if ((*board[rowIndexSrc][colIndexSrc]).getSymbol() == 'p')
        {
            // Calculating vertical and horizontal distances
            int deltaHorizontal = rowIndexDst - rowIndexSrc;
            int deltaVertical = colIndexDst - colIndexSrc;

            // horizontal distance should be 0, vertical distance should be 1 or 2, if the row is 2

            // Check if initial position
            if (rowIndexSrc == 1)
            {
                if (!(deltaVertical == 0 && (deltaHorizontal == 2 || deltaHorizontal == 1)))
                {
                    return false;
                }
            }
            else
            {
                if (!(deltaVertical == 0 && deltaHorizontal == -1))
                {
                    return false;
                }
            }

            // if no checks are triggered, initiate the move

            // Assigning the source piece to destination, and clearing the source piece
            board[rowIndexDst][colIndexDst] = board[rowIndexSrc][colIndexSrc];
            board[rowIndexSrc][colIndexSrc] = nullptr;

            return true;
        }

        return false;
    }

    void display()
    {
        cout << " \ta\tb\tc\td\te\tf\tg\th" << endl
             << endl;
        for (int i = 0; i < 8; i++)
        {
            cout << 8 - i;

            // Draw Row
            for (int j = 0; j < 8; j++)
            {
                char symbol;
                if (board[7 - i][j] != nullptr)
                {
                    symbol = (*board[7 - i][j]).getSymbol();
                }
                else
                {
                    symbol = '.';
                }

                cout
                    << "\t" << symbol;
            }
            cout << "\t" << 8 - i << endl
                 << endl;
        }
        cout << " \ta\tb\tc\td\te\tf\tg\th" << endl
             << endl;
    }
};

int main()
{
    // Header
    cout << "\n\nStudent ID: 23K0703" << endl;
    cout << "Name: Sarim Ahmed" << endl
         << endl;

    ChessBoard chessBoard;

    chessBoard.display();

    // Moving Knight
    if (chessBoard.movePiece("g1", "h3"))
    {
        cout << "Valid Move" << endl;
    }
    else
    {
        cout << "Invalid Move" << endl;
    };

    chessBoard.display();

    // Moving Pawn
    if (chessBoard.movePiece("a2", "a4"))
    {
        cout << "Valid Move" << endl;
    }
    else
    {
        cout << "Invalid Move" << endl;
    };

    chessBoard.display();

    // Moving Pawn again
    if (chessBoard.movePiece("a4", "a6"))
    {
        cout << "Valid Move" << endl;
    }
    else
    {
        cout << "Invalid Move" << endl;
    };

    chessBoard.display();
}