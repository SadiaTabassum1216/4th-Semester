CREATE OR REPLACE FUNCTION get_area(r number) 
RETURN NUMBER IS 
y number:=0;

BEGIN
SELECT r*r*3.14 INTO y FROM dual;
RETURN y;

END get_area;
/