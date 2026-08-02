console.log("hi")
//writing functions

function functionName(){
        console.log("Hello from function");
}

functionName()// without paranthesis only the reference will be called and with paranthesis the function will be called

function add(a, b){
        return a + b
}

const res = add(2, 3)
add(2, null)
add(2, 'a')
console.log(res)

function loginUser(userName){
        return `${userName} just logges in`
}

console.log(loginUser("Nikhil"))

function calculate(...num1){
        return num1
}
console.log(calculate(200, 400, 23, 35))

if(1){
        let a = 1;
        const b = 2;
        var c = 3;
}

// you cant use same variable out of the scope

// arrow function

const user = {
        userName: "Nikhil",
        print: 34,

        welcomeMessage: function(){
                console.log(`Welcome to website ${this.userName}`)
        }
}