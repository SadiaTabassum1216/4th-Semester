drop table main;

create table main(
region varchar2(25),
country varchar2(40),
city varchar2(25),
department varchar2(30),
job varchar2(35),
id number,
last_name varchar2(25),
salary number,
tax number);

declare
annual number;
tax number;
cursor c is
select region_name,country_name,city,department_name, job_title, employee_id, last_name,salary,commission_pct
from regions,countries,locations,departments,jobs,employees 
where employees.job_id=jobs.job_id and
employees.department_id=departments.department_id and
departments.location_id=locations.location_id and
locations.country_id=countries.country_id and
countries.region_id=regions.region_id;
v c%rowtype;
begin
open c;
loop
fetch c into v;
annual:=(v.salary+v.salary*nvl(v.commission_pct,0))*12;
tax:=annual*0.1;
insert into main values(v.region_name,v.country_name,v.city,v.department_name, v.job_title, v.employee_id, v.last_name,annual,tax);
exit when c%notfound;
end loop;
end;
/