# 自身连接+去除重复值
# 方案1:1126ms
select distinct First.Email 
from Person First,Person Second
where First.Id != Second.Id and
      First.Email = Second.Email;

# 方案2:1084ms 
select First.Email 
from Person First,Person Second
where First.Id != Second.Id and
      First.Email = Second.Email
group by First.Email;
