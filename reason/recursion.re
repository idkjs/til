/* 再帰的に使用する関数であることを明示する必要がある */
let rec range = (a, b) =>
  if (a > b) {
    [];
  } else {
    [a, ...range(a + 1, b)];
  };

/* tail call */
let factorial = n => {
  let rec iter = (i, n') =>
    if (i <= 1) {
      n';
    } else {
      iter(i - 1, n' * i);
    };
  iter(n, 1);
};

let () = {
  List.iter(Printf.printf("%d "), range(2, 12));
  Printf.printf("factorial of 5: %d\n", factorial(5));
};
