let f = n => {
  let rec iter = counter =>
    if (counter == n) {
      counter;
    } else {
      iter(counter + 1);
    };
  iter(0);
};

let () = Printf.printf("%d\n") @@ f(10);
