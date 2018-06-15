let isLeapYear = year =>
  year mod 4 == 0 && year mod 100 != 0 || year mod 400 == 0 ? true : false;

let dayCount = [0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365];

let getDayOfYear = (year, month, dayOfMonth) =>
  isLeapYear(year) ?
    List.nth(dayCount, month) + dayOfMonth :
    List.nth(dayCount, month) + dayOfMonth + 1;

let getDaysInMonth = (year, month) =>
  isLeapYear(year) && month + 1 == 2 ?
    List.nth(dayCount, month + 1) - List.nth(dayCount, month) + 1 :
    List.nth(dayCount, month + 1) - List.nth(dayCount, month);