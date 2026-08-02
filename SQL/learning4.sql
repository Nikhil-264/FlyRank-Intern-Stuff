-- CREATE TABLE employees(
-- 	emp_id SERIAL PRIMARY KEY,
-- 	fname VARCHAR(50) NOT NULL,
-- 	lname VARCHAR(50) NOT NULL,
-- 	email VARCHAR(100) NOT NULL UNIQUE,
-- 	dept VARCHAR(50),
-- 	salary DECIMAL(10, 2) DEFAULT 30000.00,
-- 	hire_data DATE NOT NULL DEFAULT CURRENT_DATE
-- );

-- SELECT * FROM employees;

-- ALTER TABLE employees
-- RENAME COLUMN hire_data to hire_date

-- INSERT INTO employees (emp_id, fname, lname, email, dept, salary, hire_date)
-- VALUES
-- (1, 'Raj', 'Sharma', 'raj.sharma@example.com', 'IT', 50000.00, '2020-01-15'),
-- (2, 'Priya', 'Singh', 'priya.singh@example.com', 'HR', 45000.00, '2019-03-22'),
-- (3, 'Arjun', 'Verma', 'arjun.verma@example.com', 'IT', 55000.00, '2021-06-01'),
-- (4, 'Suman', 'Patel', 'suman.patel@example.com', 'Finance', 60000.00, '2018-07-30'),
-- (5, 'Kavita', 'Rao', 'kavita.rao@example.com', 'HR', 47000.00, '2020-11-10'),
-- (6, 'Amit', 'Gupta', 'amit.gupta@example.com', 'Marketing', 52000.00, '2020-09-25'),
-- (7, 'Neha', 'Desai', 'neha.desai@example.com', 'IT', 48000.00, '2019-05-18'),
-- (8, 'Rahul', 'Kumar', 'rahul.kumar@example.com', 'IT', 53000.00, '2021-02-14'),
-- (9, 'Anjali', 'Mehta', 'anjali.mehta@example.com', 'Finance', 61000.00, '2018-12-03'),
-- (10, 'Vijay', 'Nair', 'vijay.nair@example.com', 'Marketing', 50000.00, '2020-04-19')


-- SELECT * FROM employees;

-- If we have inserted a value already in the table and lets suuppose (1, ...)
-- Where 1 is the serial
-- Can use multple conditions as well
-- SELECT * FROM employees
-- WHERE dept = 'HR';

-- DOing multiple
-- SELECT * FROM employees
-- WHERE dept = 'HR' OR dept = 'IT' OR dept = 'Finance'

-- Instead of this we can ues IN operator
-- SELECT * FROM employees

-- WHERE dept IN('HR', 'IT', 'Finance');
-- WHERE dept NOT IN('HR', 'IT', 'Finance');

-- Between usage
-- WHERE salary BETWEEN 50000 AND 65000; -- Here 50000 is included

-- Distinct clause
-- SELECT dept from employees;
-- to get the unique values only we can use
-- SELECT DISTINCT dept FROM employees;

-- orderby
-- SELECT * FROM employees ORDER BY fname; -- arranges by default in ascending order
 -- for descending order add DESC at end
-- SELECT * FROM employees ORDER BY fname DESC;

-- LIMIT
-- SELECT * FROM employees LIMIT 3; -- WIll show only the first three rows of the table

-- LIKE
-- If you want somehitng like, all employyyes whose name starts with some charcater
-- SELECT * FROM employees WHERE fname LIKE 'A%'; -- will give hte result for name starting with A and modulus can be any string
-- This operation is case sensitive;
-- for last character
-- SELECT * FROM employees WHERE fname LIKE '%a'

-- a character in the middle
-- SELECT * FROM employees WHERE fname LIKE '%i%'; --- names with i letter within

-- SELECT * FROM employees WHERE dept LIKE '__'; -- Gives all the data with which has two characters in it

-- eg if  we want to second character to be 'a' then we can do 
-- SELECT * FROM employees WHERE dept LIKE '_a%'; -- % for anything can come after a

-- Aggregate functions
-- 1. COUNT()
-- SELECT count(emp_id) FROM employees; -- Try to provide the primary key in the COUNT() as it is unique

-- 2. SUM()
-- SELECT SUM(salary) from employees;

-- 3. AVERAGE
-- SELECT AVG(salary) from employees;

-- 4. MIN
-- SELECT MIN(salary) from employees;

-- 5. MAX
-- SELECT MAX(salary) from employees;
-- GROUP BY
-- lets go with finding number of employees in each department++++
-- one column has to be common

-- select dept, COUNT(dept) from employees GROUP BY dept;
-- select dept, SUM(salary) from employees group by dept; -- avg, min, max and other aggregate functions


-- STRING FUNCTIONS
--There are different string functions
-- like concat, concat_ws, substr, left, right, length, upper, lower, trim, ltrim, rtrim, replace, position, string_agg
-- we'll see one by one

-- Concatenation
-- joining different words
-- SELECT CONCAT('Hello', 'World');
-- we can use this fnction when joining fname and lname in the table

-- SELECT emp_id, CONCAT(fname, ' ', lname) AS Fullname, dept from employees; -- As(alias gives the temporary name to the column)
-- If we are iusing the CONCAT only we have to give th space in betwen jojing the string

-- We can use the function CONCAT_WS to avoid that (with separator)
-- SELECT emp_id, CONCAT_WS(' ', fname, lname) AS Fullname, dept from employees;
-- first argumne in the above line is the separator
-- whatever column you want to add that column name as comma separated after SELECT

-- SUBSTRING function
-- SELECT SUBSTR('Hello Buddy!', 1, 5); -- Will return Hello 
-- SELECT SUBSTRING('ByteLegend' FROM 1 FOR 4); -- will return Byte

-- REPLACE function
-- syntax : REPLACE(str, from_str, to_str)
-- SELECT REPLACE('abc hola c', 'abc', 'pq'); -- will return pq hola c

-- SELECT REPLACE(dept, 'IT', 'TECH') from employees;

-- REVERSE
-- SELECT REVERSE('Hello');
-- SELECT REVERSE(fname) from employees;

-- Length function
-- SELECT LENGTH('Hello');
-- SELECT LENGTH(fname) from employees;

-- SELECT * FROM employees
-- WHERE LENGTH(fname) > 4;

-- LEFT AND RIGHT
-- SELECT LEFT('Hello World', 5); -- will give the 5 characters from left
-- U can use the right just like left for getting charaters from right

-- TRIM
-- SELECT TRIM('     kdbfv!  ');
-- SELECT LENGTH(TRIM('     kdbfv!  ')); -- youll get 6

-- POSITION
-- SELECT POSITION('om' in 'Thomas');

--EXERCISE 2
-- SELECT CONCAT_WS(':', emp_id, CONCAT_WS(' ', fname, lname), dept, salary) FROM employees
-- WHERE emp_id = 1;

--EXERCISE 4
-- Printing 
-- I1 Raju
-- H2 Priya
-- Means first letter is the dept initial and then employee id second character in that then fname
-- Solution
-- SELECT CONCAT_WS(' ', CONCAT(LEFT(dept, 1), emp_id ), fname) FROM employees LIMIT 2;


-- SELECT * FROM employees 
-- WHERE salary = (select max(salary) from employees);
-- Getting the all employees that have the highest salary 

-- Altering tables
as persson table has varchar limitset to 100, we can change th