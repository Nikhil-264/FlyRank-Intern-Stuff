const taskInput = document.querySelector('#taskInput');
const addTaskBtn = document.querySelector('#addTask');
const taskList = document.querySelector('#taskList');

addTaskBtn.addEventListener("click", addTask);
taskInput.addEventListener("keypress", function(e){
        if(e.key === "Enter"){
                addTask();
        }
})

function addTask(){
        const taskText = taskInput.value.trim();

        if(taskText === ""){
                alert("Task can not be empty!");
                return;
        }

        const li = document.createElement("li");
        li.textContent = taskText;
        li.classList.add("task");

        li.addEventListener("click", function(){
                li.classList.toggle("completed");
                saveTasks();
        });

        const deleteBtn = document.createElement("button");
        deleteBtn.textContent = "❌";
        deleteBtn.classList.add("delete-btn");
        deleteBtn.addEventListener("click", function(){
                li.remove();
                saveTasks();
        });

        li.appendChild(deleteBtn);
        taskList.appendChild(li);

        saveTasks();

        taskInput.value = "";
}

function saveTasks(){
        const tasks = [];
        document.querySelector(".task").forEach((task)=>{
                tasks.push({
                        text: task.textContent.replace("❌", "").trim(),
                        completed: task.classList.contains("completed"),
                });
        });
        localStorage.setItem("tasks", JSON.stringify(tasks));
}

function loadTasks(){
        const tasks = JSON.parse(localStorage.getItem("tasks")) || [];
        tasks.forEach(({text, completed}) =>{
                const li = document.createElement("li");
                li.textContent = text;
                li.classList.add("tasks");
                if(completed) li.classList.add("completed");

                li.addEventListener("click", function(){
                        li.classList.toggle("completed");
                        saveTasks();
                });

                const deleteBtn = document.createElement("button");
                deleteBtn.textContent = "❌";
                deleteBtn.classList.add("delete-btn");
                deleteBtn.addEventListener("click", function(){
                        li.remove();
                        saveTasks();
                });

                li.appendChild(deleteBtn);
                taskList.appendChild(li);
        })
}