const coding = ['JavaScript', 'Python', 'Java', 'C++', 'Ruby'];

const values = coding.forEach((item)=>{
        console.log(item);
})

//filer
const myNums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
const evenNums = myNums.filter((num)=>{
        return num % 2 === 0;
})
console.log(evenNums);

// chaining
const newNums = myNums
                .map((num) => num * 10)
                .map((num) => num + 2)
                .filter((num)=> num>50)

console.log(newNums);

//reducer
const sum = myNums.reduce((acc, num)=>{
        return acc + num;
}, 0)
console.log(sum);
// what is accumulator
// accumulator is the value that is returned by the function and is passed to the next iteration of the function 
// 