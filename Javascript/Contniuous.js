// let score = "Fuck You"

// console.log(typeof score);
// console.log(typeof(score));

// let valuenumber = Number(score)

// console.log(typeof(valuenumber));
// console.log(valuenumber);
// // NaN = Not a Number ==> Type = Number

// console.log(1 + 1 + "3" * 4 - 1);
// console.log(4 * "4");

// console.log(+true);

console.log("000" > 1);
console.log("02" > 1);

const bigNumber = 4938579340457394394753n
console.log(typeof(bigNumber));

const heroes = ["Shaktiman", "Hero", "perman"];
let myObj = {
        name : "Hitesh",
        age : 34,
}

const myFunction = function(){
        console.log("45");
        
}

const name = "Nikhil"
const age = 21

//stack and heap memory
console.log(`hello my name is ${name} and my age is ${age}`);
// here you have to use backticks

const gameName = new String('Clash of Clans');

console.log(gameName[0]);
console.log(gameName.__proto__);
console.log(gameName.length);
console.log(gameName.toLowerCase());
console.log(gameName.charAt('a')); //it want number as input argument but as a is not a number it get converterd to NaN and hance it return 0th index charcter
console.log(gameName.indexOf('c')); // if not present will give -1

const newString = gameName.substring(0,4);
console.log(newString)
const a = "             scjhwdc odcknso       wodfhslk    kjb                                       ";
console.log(a.trim());

console.log(Number.MIN_SAFE_INTEGER)
console.log(Number.MAX_SAFE_INTEGER)
console.log(String.MAX_VALUE)

