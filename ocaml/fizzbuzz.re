open Printf;

let fizzbuzz = n =>
  for (i in 1 to n) {
    switch (i) {
    | _ when i mod 15 == 0 => printf("FizzBuzz\n")
    | _ when i mod 5 == 0 => printf("Buzz\n")
    | _ when i mod 3 == 0 => printf("Fizz\n")
    | _ => printf("%d\n", i)
    };
  };

/* tail recurtion */
let fizzbuzz2 = n => {
  let rec iter = i => {
    let _ =
      switch (i) {
      | _ when i mod 15 == 0 => printf("FizzBuzz\n")
      | _ when i mod 5 == 0 => printf("Buzz\n")
      | _ when i mod 3 == 0 => printf("Fizz\n")
      | _ => printf("%d\n", i)
      };

    if (i < n) {
      iter(i + 1);
    };
  };

  iter(1);
};

let fizzbuzz3 = n => {
  let l = List.tl(List.init(n, e => e));
  List.iter(
    e =>
      if (e mod 15 == 0) {
        printf("FizzBuzz\n");
      } else if (e mod 5 == 0) {
        printf("Buzz\n");
      } else if (e mod 3 == 0) {
        printf("Fizz\n");
      } else {
        printf("%d\n", e);
      },
    l,
  );
};

let () = {
  fizzbuzz(20);
  fizzbuzz2(20);
  fizzbuzz3(20);
};
