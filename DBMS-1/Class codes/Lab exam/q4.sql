select distinct sailors.sname
from sailors,reserve
where sailors.sid=reserve.sid;