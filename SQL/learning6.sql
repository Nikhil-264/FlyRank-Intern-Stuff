-- FOR MANY many relationship we need more that two table as explained below
-- STUDENTS TABLE
-- CREATE TABLE students(
-- 	s_id SERIAL PRIMARY KEY,
-- 	name VARCHAR(100) NOT NULL
-- );

-- COURSES TABLE
-- CREATE TABLE courses(
-- 	c_id SERIAL PRIMARY KEY,
-- 	name VARCHAR(100) NOT NULL,
-- 	fee NUMERIC NOT NULL
-- );

-- -- ENROLLMENT TABLE
-- CREATE TABLE enrollment(
-- 	enrollment_id SERIAL PRIMARY KEY,
-- 	s_id INT NOT NULL,
-- 	c_id INT NOT NULL,
-- 	enrollment_date DATE NOT NULL,
-- 	FOREIGN KEY(s_id) REFERENCES students(s_id),
-- 	FOREIGN KEY(c_id) REFERENCES courses(c_id)
-- );

-- INSERT INTO students(name) VALUES
-- ('Raju'), ('Sham'), ('Alex');

-- INSERT INTO courses(name, fee) VALUES
-- ('Mathematics', 500), ('Physics', 600), ('Chemistry', 700);

-- SELECT * FROM enrollment;

-- INSERT INTO enrollment(s_id, c_id, enrollment_date)
-- VALUES
-- (1, 1, '2024-01-01'), -- Raju enrolled in mathematics
-- (1, 2, '2024-01-15'), -- Raju enrolled in Physics
-- (2, 1, '2024-02-01'), -- Sham enrolled in Mathematics
-- (2, 3, '2024-02-15'), -- Sham enrolled in Chemistry
-- (3, 3, '2024-03-25'); -- Alex in chemistry

-- select
-- 	s.name AS StudentName, 
-- 	c.name as CourseTaken, 
-- 	e.enrollment_date,  
-- 	c.fee AS Fees 
-- 	from
-- 		enrollment e
-- JOIN students s ON e.s_id = s.s_id
-- JOIN courses c ON c.c_id = e.c_id
-- WHERE EXTRACT(DAY FROM e.enrollment_date) = 1; -- gives data which has date as 1


