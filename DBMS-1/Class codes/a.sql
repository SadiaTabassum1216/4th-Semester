select FIRST_NAME||' '|| LAST_NAME|| '''s annual salary is '|| (SALARY+SALARY*NVL(COMMISSION_PCT,0))*12 "Total Ammount" from  EMPLOYEES;
select last_name,employee_id from employees where employee_id=&x;