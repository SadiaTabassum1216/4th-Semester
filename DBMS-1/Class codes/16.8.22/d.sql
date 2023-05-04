create or replace procedure get_area2(r in number,area out number)

IS
BEGIN
SELECT r*r*3.14 INTO area
FROM dual;
END get_area2;
/