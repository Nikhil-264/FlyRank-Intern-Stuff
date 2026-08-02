## How to setup Tailwind CSS

Step 1: Run the following commands
```
npm install -D tailwindcss
npx tailwind init
```

Step 2: Update tailwind.conf.js file to include this line:
```
content : ["*.html],
```

Step 3: create src/input.css to include:

```
@tailwind base;
@tailwind componenets;
@tailwind utilities;
```

Step 4 : Include the src/input.css file to your html

Step 5 : Run the following commmand:

```
npx tailwindcss -i ./src/input.css -o ./src/output.css -- watch
```