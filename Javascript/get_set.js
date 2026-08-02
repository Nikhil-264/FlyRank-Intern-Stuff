// getters and setters
class User{
        constructor(email, password){
                this.email = email;
                this.password = password;
        }
        // it u define getter then u have to set setter as well
        // setter ko return nhi krte
         
        get password(){
                return this._password.toUpperCase();
        }
        set password(value){
                this._password = value;
        }
}

const Nikhil = new User("Hit", "134r")
console.log(Nikhil.password)