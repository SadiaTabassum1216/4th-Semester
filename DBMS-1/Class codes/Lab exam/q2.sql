select boats.color
from boats,sailors,reserve
where boats.bid=reserve.bid and reserve.sid=sailors.sid and sailors.sname='Lubber';