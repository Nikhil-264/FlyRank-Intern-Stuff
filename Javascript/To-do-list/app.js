// Select elements
const taskInput = document.querySelector("#taskInput");
const addTaskBtn = document.querySelector("#addTask");
const taskList = document.querySelector("#taskList");

// Load tasks from local storage
// document.addEventListener("DOMContentLoaded", loadTasks);

// Add task event
addTaskBtn.addEventListener("click", addTask);
taskInput.addEventListener("keypress", function (e) {
    if (e.key === "Enter") {
        addTask();
    }
});

// Function to add a new task
function addTask() {
    const taskText = taskInput.value.trim();

    if (taskText === "") {
        alert("Task cannot be empty!");
        return;
    }

    // Create a new task item
    const li = document.createElement("li");
    li.textContent = taskText;
    li.classList.add("task");

    // Mark as completed on click
    li.addEventListener("click", function () {
        li.classList.toggle("completed");
        saveTasks();
    });

    // Delete button
    const deleteBtn = document.createElement("button");
    deleteBtn.textContent = "❌";
    deleteBtn.classList.add("delete-btn");
    deleteBtn.addEventListener("click", function () {
        li.remove();
        saveTasks();
    });

    // Append delete button to task
    li.appendChild(deleteBtn);
    taskList.appendChild(li);

    // Save tasks to local storage
    saveTasks();

    // Clear input field
    taskInput.value = "";
}

// Save tasks to local storage
function saveTasks() {
    const tasks = [];
    document.querySelectorAll(".task").forEach((task) => {
        tasks.push({
            text: task.textContent.replace("❌", "").trim(),
            completed: task.classList.contains("completed"),
        });
    });
    localStorage.setItem("tasks", JSON.stringify(tasks));
}

// Load tasks from local storage
function loadTasks() {
    const tasks = JSON.parse(localStorage.getItem("tasks")) || [];
    tasks.forEach(({ text, completed }) => {
        const li = document.createElement("li");
        li.textContent = text;
        li.classList.add("task");
        if (completed) li.classList.add("completed");

        // Click to toggle completion
        li.addEventListener("click", function () {
            li.classList.toggle("completed");
            saveTasks();
        });

        // Delete button
        const deleteBtn = document.createElement("button");
        deleteBtn.textContent = "❌";
        deleteBtn.classList.add("delete-btn");
        deleteBtn.addEventListener("click", function () {
            li.remove();
            saveTasks();
        });

        li.appendChild(deleteBtn);
        taskList.appendChild(li);
    });
}
