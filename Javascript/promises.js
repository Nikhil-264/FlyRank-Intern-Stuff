const PromiseOne = new Promise(function(resolve, reject) {
    //Do an async task
    //DB calls, cryptography, network
    setTimeout(function() {
        console.log("Async task is complete");
        resolve('Success');
    }, 1000);
}); 

PromiseOne.then(function(){
        console.log("Next Task");
});

new Promise(function(resolve, reject) {
        setTimeout(function(){
                console.log("Async Task 2");
                resolve();
        }, 1000)
}).then(function(){
        console.log("Async Task 2 resolved");
});


const promiseThree = new Promise(function(resolve, reject) {
    setTimeout(function() {
        resolve({username : "chai", email :"abd@.com"});
    }, 1000);
}).then(function(user){
    console.log(user);
}); // The paramter htat is passed in the resolve that is object and that object is passed to the then function as a parameter
// Here the object is passed to then in user parameter

// const promiseFour = new Promise(function(resolve, reject) {
//         setInterval(function() {
//                 let error = false;
//                 if(!error){
//                         resolve({username : "chai", email :"abd@.com"});
//                 }else{
//                         reject('ERROR : Something went wrong');
//                 }
//         }, 1000);
// })

// promiseFour
// .then((user)=>{
//         console.log(user);
//         return user.username;
// })
// .then((username) =>{
//         console.log(username);
// })
// .catch(function(error){
//         console.log(error);
// })
// .finally(function(){
//         console.log("Th epromise is either resolved or rejected");
// })


const promiseFive = new Promise(function(resolve, reject) {
        // let counter = 0;
        setTimeout(function() {
                let error = false;
                if(!error){
                        // clearInterval(intervalID);
                        resolve({username : "js", password :"123"});
                }else{
                        // clearInterval(intervalID);
                        reject('ERROR : JS went wrong');
                }
                // counter++;
        }, 1000);
})

async function consumePromiseFive(){
        const response = await promiseFive;
        console.log(response.username);
}

consumePromiseFive();

async function getAllUsers(){
        try {
                const response = await fetch('https://jsonplaceholder.typicode.com/users');
                const data = await response.json();
                console.log(data);
        } catch (error) {
                console.log(error);
        }
};

getAllUsers();
fetch('https://jsonplaceholder.typicode.com/users')
.then(response => {
        return response.json();
})
.then(() => {
        console.log(data);
})
.catch(error => {
        console.log(error);
})

// u can see tha tin the terminal the data fetched is printed before all the other function calling even though the fetch is at the end
// this is because the fetch is async and the other functions are sync so the fetch will be executed first and then the other functions will be executed
// fetch will be executed first
