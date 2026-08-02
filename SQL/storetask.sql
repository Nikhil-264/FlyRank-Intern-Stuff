-- customers

-- CREATE TABLE customers(
-- 	cust_id SERIAL PRIMARY KEY,
-- 	cust_name VARCHAR(100) NOT NULL
-- );

-- INSERT INTO customers(cust_name)
-- VALUES
-- ('Raju'), ('Sham'), ('Paul'), ('Alex');

-- SELECT * FROM customers;

-- orders

-- CREATE TABLE orders(
-- 	ord_id SERIAL PRIMARY KEY,
-- 	ord_date DATE NOT NULL,
-- 	cust_id INTEGER NOT NULL,
-- 	FOREIGN KEY(cust_id) REFERENCES customers(cust_id)
-- );

-- INSERT INTO orders (ord_date, cust_id)
-- VALUES
--     ('2024-01-01', 1),  -- Raju first order
--     ('2024-02-01', 2),  -- Sham first order
--     ('2024-03-01', 3),  -- Paul first order
--     ('2024-04-04', 2);  -- Sham second order

-- SELECT * FROM orders;

-- orderItems Table

-- CREATE TABLE order_items(
-- 	item_id SERIAL PRIMARY KEY,
-- 	ord_id INTEGER NOT NULL,
-- 	p_id INTEGER NOT NULL,
-- 	quantity INTEGER NOT NULL,
-- 	FOREIGN KEY(ord_id) REFERENCES orders(ord_id),
-- 	FOREIGN KEY(p_id) REFERENCES products(p_id)
-- );

-- INSERT INTO order_items (ord_id, p_id, quantity)
-- VALUES
--     (1, 1, 1),  -- Raju ordered 1 Laptop
--     (1, 4, 2),  -- Raju ordered 2 Cables
--     (2, 1, 1),  -- Sham ordered 1 Laptop
--     (3, 2, 1),  -- Paul ordered 1 Mouse
--     (3, 4, 5),  -- Paul ordered 5 Cables
--     (4, 3, 1);  -- Sham ordered 1 Keyboard

-- CREATE TABLE products (
--     p_id SERIAL PRIMARY KEY,
--     p_name VARCHAR(100) NOT NULL,
--     price NUMERIC NOT NULL
-- );

-- INSERT INTO products (p_name, price)
-- VALUES
--     ('Laptop', 55000.00),
--     ('Mouse', 500),
--     ('Keyboard', 800.00),
--     ('Cable', 250.00)
-- ;

-- SELECT * FROM order_items;

-- SELECT
-- 	c.cust_name,
-- 	o.ord_date,
-- 	p.p_name,
-- 	p.price,
-- 	oi.quantity,
-- 	(oi.quantity * p.price) AS Total_price
-- FROM
-- 	order_items oi
-- 	JOIN products p ON oi.p_id = p.p_id
-- 	JOIN orders o ON o.ord_id = oi.ord_id
-- 	JOIN customers c ON o.cust_id = c.cust_id;

-- SELECT p_name, sum(Total_price) from
-- billing_info
-- 	GROUP BY p_name;
-- 	HAVING sum(Total_price) > 1500; -- When applying condition for group by, use having clause

-- GROUP BY ROLLUP

-- SELECT 
-- 	COALESCE(p_name, 'Total'), -- if there is a null in the p_name column, it will be comverted to Total(the 2nd argument string) 
-- 	sum(Total_price) AS Amount
-- from
-- 	billing_info
-- 	GROUP BY ROLLUP(p_name) ORDER BY amount; -- Roll upwill add the end row which groups the column given like sum in thsi example

-- STORES ROUTINE
-- An SQL statemtn or a ser of SQL statement that can be stores on database sever which can be called no. of times
-- Two types : 1. Stored Procedure
-- 2. User defined functions

-- Stored procedeures -- set of SQL statements and procedural logic that can perform operation such as inserting, updating, deleting and querying data
-- Before this storedatabase is used

-- STORES ROUTINE
-- An SQL statemtn or a ser of SQL statement that can be stores on database sever which can be call no. of times
-- FRom this bankData database is used

-- SELECT * FROM employees;

-- UPDATE employees
-- 	set salary = 97000
-- Where emp_id = 4;
-- If updating many values, this method can be lengthy
-- for that we can use the stored procedures
-- SYNTAX

-- CREATE OR REPLACE PROCEDURE procedur_name(parameter_name, parameter_type, ....)
-- LANGUAGE plpgsql
-- AS $$
-- BEGIN
-- 	-- procedural code here
-- END;
-- $$;

-- We'll see the example of making a procedure for above change salary operaion
-- ITs like functions in other languages

-- CREATE OR REPLACE PROCEDURE update_emp_salary(
-- 	p_employee_id INT,
-- 	p_new_salary NUMERIC
-- )

-- LANGUAGE plpgsql
-- AS $$
-- BEGIN
-- 	UPDATE employees
-- 	SET salary = p_new_salary
-- 	WHERE emp_id = p_employee_id;
-- END;
-- $$;

-- Now u can so above operation with the line
-- CALL update_emp_salary(3, 71000); 

--Another procedure to add employee

-- CREATE OR REPLACE PROCEDURE add_employee(
-- 	p_fname VARCHAR,
-- 	p_lname VARCHAR,
-- 	p_email VARCHAR,
-- 	p_dept VARCHAR,
-- 	p_salary NUMERIC
-- )
-- LANGUAGE plpgsql
-- AS $$
-- BEGIN
-- 	INSERT INTO employees(fname, lname, email, dept, salary)
-- 	VALUES(p_fname, p_lname, p_email, p_dept, p_salary);
-- END;
-- $$;

-- USER DEFINED FUNCTIONS -- custom function created by user to perform specific opetiaons ans return a value,

-- SYNTAX -- 

-- CREATE OR REPLACE FUNCTION function_name(parameters)
-- RETURN return_type AS $$
-- BEGIN
-- 	--Function body(SQL statements)
-- 	RETURN some_value; -- for scalar functions
-- END;
-- $$ LANGUAGE plpgsql;

-- eg. find name of the employees in each department having maximu salary
-- Normal method
-- SELECT 
-- 		e.emp_id,
-- 		e.fname,
-- 		e.salary
-- 	FROM
-- 		employees e
-- 	WHERE e.dept = 'HR'
-- 		AND e.salary = (
-- 			SELECT MAX(emp.salary)
-- 			FROM employees emp
-- 			WHERE emp.dept = 'HR'
-- 		);
		-- we have to write this query for ech department we can avoid that and make user defined function

-- CREATE OR REPLACE FUNCTION dept_max_sal_emp1(dept_name VARCHAR)
-- RETURNS TABLE(emp_id INT, fname VARCHAR, salary NUMERIC)
-- AS $$ 
-- BEGIN
-- 	RETURN QUERY
-- 	SELECT 
-- 		e.emp_id, e.fname, e.salary
-- 	FROM
-- 		employees e
-- 	WHERE 
-- 		e.dept = dept_name
-- 		AND e.salary = (
-- 			-- This is a subquery
-- 			SELECT MAX(emp.salary)
-- 			FROM employees emp
-- 			WHERE emp.dept = dept_name
-- 		);
-- END;
-- $$ LANGUAGE plpgsql;
-- calling user defined functions

-- SELECT * FROM dept_max_sal_emp1('HR');


--WINDOWS FUNCTION alos known as analytic function allow you to perform calculations across a ser of row related to the crrent row
-- DEfinned by an OVER() clause

-- SELECT fname, salary,
-- 	SUM(salary) OVER(ORDER BY salary) -- will give cumulative summation
-- 	from employees;

-- BENEfits of windows functions

-- 1. Advances analytics : They enable complex calculations like running totals, moving averages, rank calculations and cumulatice distributions
-- 2. Non-Aggregating : Unlike aggregate function, windows function do not collapse rows. This means you can calculate aggregate while retaining individual row details
-- 3. Flexibility: They can be used in various clauses of SQL, suhc as SELECT, ORDER BY, Having providing a lot of flexibility in writing quesries

-- SELECT fname, salary,
-- 	AVG(salary) OVER(ORDER BY salary) -- will give cumulative summation
-- 	from employees;

-- SELECT fname, salary,
-- 	SUM(salary) OVER(ORDER BY salary) -- will give cumulative summation
-- 	from employees;

-- ROW_NUMBER
-- SELECT
-- 	ROW_NUMBER() OVER(PARTITION BY dept),
-- 	fname, dept, salary
-- 	FROM employees;

--RANK
-- SELECT
-- 	fname, salary,
-- 	RANK() OVER(ORDER BY salary DESC)
-- 	-- fname, dept, salary
-- 	FROM employees;

-- DENse Rank
-- SELECT
-- 	fname, salary,
-- 	DENSE_RANK() OVER(ORDER BY salary DESC)
-- 	-- fname, dept, salary
-- 	FROM employees;

-- LAG/LEAD --usecase
-- SELECT
-- 	fname, salary,
-- 	(salary - LEAD(salary) OVER(ORDER BY salary DESC)) AS Salary_diff
-- 	-- fname, dept, salary
-- 	FROM employees;

-- understand CTE(COMMON TABLE EXPRESSION) is a temporary result set that you can define within a query to simplify complex SQL statements

-- SYNTAX
-- WITH cte_name(optional_column_list) AS(
-- 	-- CTE query definition
-- 	SELECT..
-- )
-- -- Main Query referring the CTE
-- SELECT...
-- FROM cte_name
-- WHERE ...;

-- USe case 1 - We want to calculate the average salary per departmen and then find all employees whose salart is above the average salary of their department
-- SELECT * FROM employees;

-- WITH avg_sal AS(
-- 	SELECT dept, AVG(salary) as avg_salary from employees GROUP by dept
-- ) -- This ipart is not stored, u cannt use this query only it wont give any result, you have to write furthur and it can be use in the same query only, 

-- SELECT
-- 	e.emp_id, e.fname, e.dept, e.salary,  a.avg_salary
-- FROM employees e
-- 	JOIN avg_sal a ON e.dept = a.dept
-- 	WHERE e.salary > a.avg_salary;

-- USe case 2 --  we want to find the highest paid employee in the each department

-- WITH max_sal AS(
-- 	select dept, max(salary) as max_salary from employees GROUP BY dept
-- )
-- SELECT 
-- 	e.emp_id, e.fname, e.dept, e.salary
-- FROM employees e
-- JOIN max_sal m ON e.dept = m.dept
-- WHERE e.salary = m.max_salary

-- TRIGGERS in SQL
-- Triggers are speacial procedures in a database that automatically execute predefined actions in response to certain events on a specified table or view
-- SYNTAX
-- CREATE TRIGGER trigger_name
-- {BEFORE | AFTER | INSTEAD OF} {INSERT | UPDATE | DELETE | TRUNCATE}
-- ON table_name
-- FOR EACH{ROW | STATEMENT}
-- EXECUTE FUNCTION trigger_function_name();


-- CREATE OR REPLACE FUNCTION trigger_function_name()
-- RETURNS TRIGGER AS $$
-- BEGIN
-- 	-- Trigger logic here
-- 	RETURN NEW;
-- END;
-- $$ LANGUAGE plpgsql;

-- USE CASE 1

-- Create a trigger soo that if we insert/update negative salary in a tabl it will be triggered and set it to 0
-- SELECT * FROM employees;

-- CALL update_emp_salary(1, -53000)

-- CREATE OR REPLACE FUNCTION check_salary()
-- RETURNS TRIGGER AS $$
-- BEGIN
-- 	IF NEW.salary < 0 THEN
-- 		NEW.salary = 0;
-- 	END IF;
-- 	RETURN NEW;
-- END;
-- $$ LANGUAGE plpgsql;

-- CREATE TRIGGER before_update_salary
-- BEFORE UPDATE ON employees
-- FOR EACH ROW
-- EXECUTE FUNCTION check_salary();

-- u can see now that if we update the salary to the negative salary, you can see that it set to 0

-- ALTER USER postgres WITH PASSWORD 'postgres';
-- SELECT current_user;
-- SELECT current_database();
\q
