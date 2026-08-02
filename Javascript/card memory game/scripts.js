const gameBoard = document.getElementById("gameBoard");
const scoreDisplay = document.getElementById("score");
const timerDisplay = document.getElementById("timer");
const resetButton = document.getElementById("reset");

let cardValues = ["🍎", "🍌", "🍇", "🍉", "🥭", "🍍", "🍓", "🍒"];
cardValues = [...cardValues, ...cardValues]; // Duplicate for pairs

let firstCard = null;
let secondCard = null;
let score = 0;
let matchedPairs = 0;
let timer;
let seconds = 0;
let gameStarted = false;
let gameActive = true;

// Shuffle the cards
cardValues.sort(() => Math.random() - 0.5);

// Function to create cards
function createCards() {
    gameBoard.innerHTML = ""; 
    cardValues.forEach((icon, index) => {
        const card = document.createElement("div");
        card.classList.add("card");
        card.setAttribute("data-value", icon);
        card.setAttribute("data-index", index);
        card.innerHTML = "?";
        card.addEventListener("click", flipCard);
        gameBoard.appendChild(card);
    });
}

// Function to start the timer
function startTimer() {
    timer = setInterval(() => {
        seconds++;
        timerDisplay.textContent = `Time: ${seconds}s`;
    }, 1000);
}

// Function to flip a card
function flipCard(event) {
    if (!gameStarted) {
        gameStarted = true;
        startTimer();
    }

    let clickedCard = event.target;

    // Prevent flipping if the card is already flipped or if it's the same as the first card
    if (clickedCard.classList.contains("flip") || clickedCard === firstCard || !gameActive) return;

    // Add the 'flip' class to trigger the flip animation
    clickedCard.classList.add("flip");
    clickedCard.textContent = clickedCard.getAttribute("data-value");

    // Check if this is the first card
    if (!firstCard) {
        firstCard = clickedCard;
    } else {
        secondCard = clickedCard;
        checkMatch();
    }
}

// Function to check if two cards match
function checkMatch() {
    if (firstCard.getAttribute("data-value") === secondCard.getAttribute("data-value")) {
        score += 5;
        matchedPairs++;
        firstCard = null;
        secondCard = null;

        // Check if all pairs are matched
        if (matchedPairs === cardValues.length / 2) {
            clearInterval(timer);
            alert(`🎉 You won! Score: ${score}, Time: ${seconds}s`);
            gameActive = false;
        }
    } else {
        score -= 1;
        setTimeout(() => {
            firstCard.textContent = "?";
            secondCard.textContent = "?";
            firstCard.classList.remove("flip");
            secondCard.classList.remove("flip");
            firstCard = null;
            secondCard = null;
        }, 500);
    }

    scoreDisplay.textContent = `Score: ${score}`;
}

// Function to reset the game
function resetGame() {
    clearInterval(timer);
    score = 0;
    seconds = 0;
    matchedPairs = 0;
    gameStarted = false;
    gameActive = true;
    firstCard = null;
    secondCard = null;
    scoreDisplay.textContent = "Score: 0";
    timerDisplay.textContent = "Time: 0s";

    cardValues.sort(() => Math.random() - 0.5); // Reshuffle cards
    createCards();
}

// Initialize game
createCards();
resetButton.addEventListener("click", resetGame);
