select name
from students
where Marks > 75
order by right(name, 3) asc, id asc;