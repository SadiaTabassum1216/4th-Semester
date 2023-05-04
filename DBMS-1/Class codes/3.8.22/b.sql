CREATE OR REPLACE PROCEDURE formatting(p_phone_no IN OUT table1.phone%type)
IS
BEGIN
p_phone_no := '(' || SUBSTR(p_phone_no,1,3) ||') ' || SUBSTR(p_phone_no,4,3) ||'-' || SUBSTR(p_phone_no,7);
END add_line;
/