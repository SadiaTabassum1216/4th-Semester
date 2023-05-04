select sname
from sailors,reserve
where sailors.sid=reserve.sid and reserve.bid=103;