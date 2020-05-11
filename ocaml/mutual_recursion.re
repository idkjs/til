let rec even = n =>
  if (n == 0) {
    true;
  } else {
    odd(n - 1);
  }
and odd = n =>
  if (n == 0) {
    false;
  } else {
    even(n - 1);
  };

let () = Printf.printf("%B\n", even(10));
