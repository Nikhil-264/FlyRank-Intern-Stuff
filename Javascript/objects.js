// singleton 

//objects literals
//u can also make a object  using
// Object.create() 
const mySym = Symbol("My own symbol"); //  deaclreing a symbol

const jsUser = {
        name: 'John', // keys : values
        age: 30,
        [mySym] : 'secret', // to maintain its symbolity otherwise it will be converted to string
        "college name": "IIT", // u can not acces this using . operator
        location : 'USA',
        email: "nikhil@boom.com",
        isLoggedIn: false,
        lastLoginDays : ["Monday", "Tuesday", "Wednesday", "Thursday"],
}

//accessing object
console.log(jsUser.name);
console.log(jsUser["name"]); // argument should be in strings
console.log(jsUser["college name"]); // argument should be in strings

jsUser.name = "Nikhil"; // to change the value of the key
// Object.freeze(jsUser); // to make object immutable

jsUser.greeting = function() {
        console.log(`Hello ${this.name}`);
}

jsUser.greeting();

