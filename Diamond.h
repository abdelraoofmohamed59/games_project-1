/**
 * @file Diamond.h
 * @brief Header file for the Diamond Tic-Tac-Toe game logic and user interface.
 *
 * This file defines the Diamond_Board class, which manages the 7×7 diamond-shaped board,
 * win condition checking (line of 3 + line of 4 in different directions), and board updates.
 * It also defines the Diamond_UI class for player creation and input handling.
 */

#ifndef Diamond_CLASSES_H
#define Diamond_CLASSES_H

#include "BoardGame_Classes.h"
 
#include <vector>
using namespace std;

/**
 * @class Diamond_Board
 * @brief Represents a 7×7 diamond-shaped board with 25 playable cells.
 *
 * The board is arranged in a diamond pattern where only 25 cells are playable.
 * Win condition requires forming both a line of 3 and a line of 4 in different directions,
 * sharing at most 1 cell between them.
 */
class Diamond_Board : public Board<char> {
private:
    char blank_symbol = '.'; ///< Character used to represent an empty cell on the board.

public:
    /**
     * @brief Constructs a 7×7 board initialized in a diamond pattern.
     */
    Diamond_Board();

    /**
     * @brief Updates the board with the player's move.
     * @param move Pointer to a Move object containing coordinates and symbol.
     * @return true if the move is valid and applied, false otherwise.
     */
    bool update_board(Move<char>* move);

    /**
     * @brief Loss is not applicable in Diamond Tic Tac Toe.
     * @return Always returns false.
     */
    bool is_lose(Player<char>* player) { return false; }

    /**
     * @brief Checks if the player has won by forming both a line of 3 and a line of 4.
     *        The lines must be in different directions and share at most 1 cell.
     * @param player Pointer to the player to check.
     * @return true if player has won, false otherwise.
     */
    bool is_win(Player<char>* player);

    /**
     * @brief Checks if the game ended in a draw.
     * @param player Pointer to a player (unused).
     * @return true if all 25 cells are filled and no player has won.
     */
    bool is_draw(Player<char>* player);

    /**
     * @brief Determines if the game has ended (win or draw).
     * @param player Pointer to a player to check win condition.
     * @return true if game is over, false otherwise.
     */
    bool game_is_over(Player<char>* player);

    /**
     * @brief Helper function to check if a line of specific length exists.
     * @param x Starting row index.
     * @param y Starting column index.
     * @param dir Direction index (0=vertical, 1=horizontal, 2=main diagonal, 3=anti-diagonal).
     * @param length Required line length (3 or 4).
     * @param sym Player's symbol to check.
     * @return true if valid line exists, false otherwise.
     */
    bool check_line(int x, int y, int dir, int length, char sym);
};

/**
 * @class Diamond_UI
 * @brief User interface for the Diamond Tic Tac Toe game.
 */
class Diamond_UI : public UI<char> {
private:
    char blank_symbol = '.'; ///< Character used to represent an empty cell.
    
public:
    /**
     * @brief Constructs the UI with title "Welcome to Diamond Tic Tac Toe".
     */
    Diamond_UI();
    
    ~Diamond_UI() {};

    /**
     * @brief Creates a human or AI player and prints a confirmation message.
     * @param name Player's name.
     * @param symbol Player's symbol ('X' or 'O').
     * @param type Player type (HUMAN or COMPUTER).
     * @return Pointer to the created Player object.
     */
    Player<char>* create_player(string& name, char symbol, PlayerType type);
    
    /**
     * @brief Requests a move from a human or AI player.
     *        For humans: prompts for cell number (1-25).
     *        For AI: uses minimax algorithm with alpha-beta pruning.
     * @param player Player whose move is requested.
     * @return Pointer to a Move object containing coordinates and symbol.
     */
    Move<char>* get_move(Player<char>* player);

    /**
     * @brief Displays the diamond-shaped board with cell numbers for reference.
     * @param matrix The board matrix to display.
     */
    void display_board_matrix(const vector<vector<char>>& matrix) const override;
};

#endif
