function scatterImages() {
  const message = document.getElementById("message");
  message.classList.remove("hidden");
  message.classList.add("visible");

  const directions = [
    [-1, -1], [0, -1], [1, -1],
    [-1,  0],         [1,  0],
    [-1,  1], [0,  1], [1,  1]
  ];

  const scatterArea = document.getElementById("scatter-area");
  scatterArea.innerHTML = ""; // clear previous

  for (let i = 0; i < 8; i++) {
    const img = document.createElement("img");
    img.src = `images/img${i + 1}.png`;
    img.style.top = "50%";
    img.style.left = "50%";
    img.style.transform = "translate(-50%, -50%)";
    img.classList.add("scatter-image");

    scatterArea.appendChild(img);

    requestAnimationFrame(() => {
      const [dx, dy] = directions[i];
      const distance = 200;
      img.style.transform = `translate(${dx * distance}px, ${dy * distance}px)`;
    });
  }

  generateHearts(); // play heart animation
}

function generateHearts() {
  for (let i = 0; i < 20; i++) {
    const heart = document.createElement("div");
    heart.className = "heart";
    heart.style.left = `${Math.random() * 100}%`;
    document.body.appendChild(heart);

    setTimeout(() => {
      heart.remove();
    }, 3000);
  }
}
