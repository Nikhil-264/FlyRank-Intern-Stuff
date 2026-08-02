document.addEventListener("DOMContentLoaded", () => {
        const board = document.querySelector(".board");
        const cells = document.querySelectorAll(".cell");
        const statusText = document.querySelector(".status");
        const resetBtn = document.querySelector(".reset");

        let currentPlayer = "X";
        let boardState = ["", "", "", "", "", "", "", "", ""];
        let gameActive = true;

        // Winning conditions
        const winningConditions = [
                [0, 1, 2], [3, 4, 5], [6, 7, 8],
                [0, 3, 6], [1, 4, 7], [2, 5, 8],
                [0, 4, 8], [2, 4, 6]
        ];

        // Function to handle a cell click
        function handleCellClick(event) {
                const cellIndex = event.target.getAttribute("data-index");

                if (boardState[cellIndex] !== "" || !gameActive) return;

                boardState[cellIndex] = currentPlayer;
                event.target.textContent = currentPlayer;

                checkWinner();
        }

        // Function to check for a winner
        function checkWinner() {
                let roundWon = false;

                for (let condition of winningConditions) {
                        let [a, b, c] = condition;
                        if (boardState[a] && boardState[a] === boardState[b] && boardState[a] === boardState[c]) {
                                roundWon = true;
                                break;
                        }
                }

                if (roundWon) {
                        statusText.textContent = `${currentPlayer} Wins! 🎉`;
                        gameActive = false;
                } else if (!boardState.includes("")) {
                        statusText.textContent = "It's a Draw! 😐";
                        gameActive = false;
                } else {
                        currentPlayer = currentPlayer === "X" ? "O" : "X";
                        statusText.textContent = `Player ${currentPlayer}'s turn`;
                }
        }

        // Function to reset the game
        function resetGame() {
                boardState = ["", "", "", "", "", "", "", "", ""];
                gameActive = true;
                currentPlayer = "X";
                statusText.textContent = `Player X's turn`;

                // Clear all cells
                cells.forEach(cell => {
                        cell.textContent = "";
                });
        }

        // Add event listeners
        cells.forEach(cell => cell.addEventListener("click", handleCellClick));
        resetBtn.addEventListener("click", resetGame);
});
