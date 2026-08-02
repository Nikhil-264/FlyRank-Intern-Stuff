// const myArr = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];// always declare array in square brackets
// // console.log(myArr[0]); // to access array element 

// const myHeroes = ['Ironman', 'Spiderman', 'Hulk', 'Thor', 'Captain America', 'Black Widow', 'Hawkeye'];

// console.log(myHeroes.length);
// // .unshift() // add element at the beginning
// // .push(), .pop() 
// // .shift() // remove element from the beginning
// // .splice() // remove element from the middle
// // myArr.splice(2, 1); // 2 is the index and 1 is the number of element to remove
// //console.log(myArr);

// // const newArr = myArr.join()
// // console.log(newArr); // joins give array in the lust form

// console.log(myArr);
// const newArr2 = myArr.slice(2, 5); // 2 is the starting index and 5 is the ending index
// console.log(myArr);
// // console.log(newArr2);// element from index 2 to 4

// const anotherArray = myArr.splice(2, 5); // removes 5 element from the index starting from 2 
// // splice makes changes in the original array
// console.log("Original ", myArr);
// console.log("slice ", newArr2);// element from index 2 to 4
// // console.log("splice ", anotherArray);

const marvelHeroes = ['Ironman', 'Spiderman', 'Hulk', 'Thor', 'Captain America', 'Black Widow', 'Hawkeye'];
const dcHeroes = ['Batman', 'Superman', 'Wonder Woman', 'Flash', 'Aquaman', 'Cyborg'];

// marvelHeroes.push(dcHeroes); // this will not concatanate the original array but add the whole ahole array as a single element
console.log(marvelHeroes);

const oneMoreArray = marvelHeroes.concat(dcHeroes); // this will concatanate the original array
console.log(oneMoreArray);
// concat will return new array


const allNewHeroes = [...marvelHeroes, ...dcHeroes]; // this is the new way to concatanate array
console.log(allNewHeroes); // this is more prefarable than concat

//there is array of random elements
const another_array = [1, 3, 5, [7, 9, 11], 13, 15, [17, 19, [21, 45]]];

const flatArray = another_array.flat(1); // 2 is the depth of the array till which it will flat thing out
console.log(flatArray); // you can use infinity to flat whatever depth is there

console.log(Array.from("Nikhil")); // will generate the array of letter of the name

let score1 = 10;
let score2 = 20;
let score3 = 30;
let score4 = 40;
console.log(Array.of(score1,score2, score3, score4))