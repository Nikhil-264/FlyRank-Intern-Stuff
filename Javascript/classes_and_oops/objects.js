function multiplyBy5(num) {
  return num * 5;
}

multiplyBy5.power = 2;

console.log(multiplyBy5(2)); // 10
console.log(multiplyBy5.power); // 2
console.log(multiplyBy5.prototype); // [Function: multiplyBy5] { power: 2 }
// function is a object too

// function, Array, null, string all are Object

function createUser(username, score){
        this.username = username;
        this.score = score;
}

createUser.prototype.increment = function(){
        this.score++;
}

createUser.prototype.printMe = function(){
        console.log(this.username, this.score);
}

const chai = new createUser("chai", 10);
const coffee = new createUser("coffee", 100);//if u dont use new keyword it will igve you the eror

console.log(chai)
chai.printMe(); // without new : cannot read properties of undefined
// Without new, this doesn't refer to a new object, and the function returns undefined, causing errors when trying to use methods like printMe().

/* 
Heres what happens behind the scenes when the new keyword is used:

A new object is created : the new keyword initiates the creation of a new js object

A prototype is linked  : the newly created object is linked to the function's prototype of the constructor function.This means that it has access to properties and methods defined on the construtor prototype
*/