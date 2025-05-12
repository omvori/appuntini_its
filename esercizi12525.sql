SELECT * 
	FROM salaries

SELECT *
	FROM employees
	
CREATE SCHEMA esercizi

--es1
SELECT *
	FROM salaries
		WHERE salary > 60000 
DROP TABLE esercizi.impiegati_over60

CREATE TABLE esercizi.impiegati_over60 AS (
	SELECT *
		,CASE
			WHEN salary > 90000
				THEN 'Bonus'
			ELSE 'No bonus'
		 END AS bonus

	FROM salaries
		WHERE salary>60000
			
)

SELECT MAX (salary) as max_salary
	FROM salaries 


SELECT COUNT(DISTINCT  emp_no) AS impiegati_ricchi
	FROM salaries
		WHERE salary > 60000

--ES 2
DROP TABLE esercizio2

CREATE TABLE esercizi.esercizio2(
	SELECT *
		,CONCAT(LEFT(first_name,2) , LEFT(last_name,2) ) AS id_code 
		,EXTRACT(year from age (current_date, birth_date)) as eta
		,EXTRACT(year from age(hire_date,birth_date)) as eta_assunzione
		FROM employees
			ORDER BY eta_assunzione ASC 
)
--es 3
SELECT *
	FROM titles

	
CREATE TABLE esercizi.esercizi3(
	SELECT *
		FROM titles
		WHERE title like 'Senior%'
			AND EXTRACT(year from from_date) BETWEEN 1990 AND 1999
		ORDER BY from_date DESC

	SELECT COUNT(DISTINCT emp_no)
		FROM titles
			WHERE title like 'Senior%'
)

--ES 4
DROP TABLE esercizi.esercizio4

CREATE TABLE esercizi.esercizio4(
	nomecogn_emp varchar(50)
	, sex varchar(1)
	, 
)
SELECT *
	FROM