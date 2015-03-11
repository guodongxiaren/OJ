# 自身连接
select First.Name
from Employee First,Employee Second
where First.ManagerId = Second.Id and 
      First.Salary > Second.Salary;
