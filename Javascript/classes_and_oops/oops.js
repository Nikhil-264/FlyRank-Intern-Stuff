const user = {
        username : "Nikhil",
        loginCount : 8,
        signedIn : true,

        getUserDetails: function(){
                // console.log("Got Data");
                // console.log(`Username is ${this.username}`);      
                console.log(this.username);
        }
}

// user.getUserDetails();

// const promiseOne = new Promise();
// const date = new Date();

function User(username, logincount, isLoggedin){
        this.username = username;
        this.logincount = logincount;
        this.isLoggedin = isLoggedin;

        return this;
}

const userOne = new User("Nikhil", 8, true);
const userTwo = new User("Mahesh", 69, false);
console.log(userOne); // undefined
console.log(userTwo); // undefined
// If u dont use new
// this will overwrite the global object