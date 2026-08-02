// Math library : Already build in in js
console.log(Math);
console.log(Math.SQRT1_2)

console.log(Math.floor(Math.random() * 10));


let myDate = new Date()
console.log(myDate.toString());
console.log(myDate.toDateString());
console.log(myDate.toISOString());
console.log(myDate.toJSON());
console.log(myDate.toLocaleString());
console.log(typeof myDate);

let myCreateDate = new Date(2025, 2, 5) // year, month starts from zero(orignial date - 1), date
console.log(myCreateDate.toDateString());

//aother date method
let myAnotherCreateDate = new Date(2025, 2, 5, 25, 3) // after year, month, date, we have hour and minutes 24 hr format // if you do 25 hr it will shift to next day
console.log(myAnotherCreateDate.toLocaleString());

// to declare format you can do that  in string in my Date argumnet
let anotherDate = new Date("5-01-2025") // here months from 01
// let anotherDate = new Date("2025-01-05") // here months from 01 lke this
console.log(anotherDate.toDateString());
//Timestamps

let myTimeStamps = Date.now()
console.log(myTimeStamps); //  this will print a a millisecond value from the date january 1st 1970
console.log(anotherDate.getTime()); // will return millisecond values from same date methioned above

// to convert millisecond to seconds
console.log(Math.floor(Date.now()/1000)) // to convert into second, Math to avoid decimal

let newDate = new Date()
console.log(newDate);
console.log(newDate.getMonth()); //string from 0

newDate.toLocaleString('default', {
        weekday: "long", // to customize format of date        
})



