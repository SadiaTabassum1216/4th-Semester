 declare
   v_counter number:=0;
   begin
   loop
   dbms_output.put_line('v_counter= '||v_counter);
	v_counter:=v_counter+1;
  exit when v_counter>10;
    end loop;

   
   end;
/
 