declare
num1 number:=&num1;
num2 number:=&num2;
num3 number:=&num3;
temp number;
begin
if num1>num2 and num1>num3
	then temp:=num1;
elsif num2>num1 and num2>num3
	then temp:=num2;
else
	temp:=num3;
	end if;
dbms_output.put_line(temp);
end;
/
