let geo_mean = ((x, y)) => (x *. y) ** 0.5;

let bmi = ((name, weight, height)) => {
  let bmi_ = weight /. height ** 2.0;
  let status =
    if (bmi_ < 18.5) {
      "やせています";
    } else if (bmi_ >= 18.5 && bmi_ < 25.0) {
      "標準です";
    } else if (bmi_ >= 25.0 && bmi_ < 30.0) {
      "肥満です";
    } else {
      "高度肥満です";
    };

  Printf.sprintf("%sさんは%s", name, status);
};

let sum_and_diff = ((x, y)) => (x + y, x - y);

let f = ((x, y)) => {
  let x' = (x + y) / 2;
  (x', x' - y);
};

let () = {
  Printf.printf("%F\n", geo_mean((3.0, 1.0)));
  Printf.printf("%s\n", bmi(("田中", 168.0, 53.0)));
  let (x, y) = f(sum_and_diff((10, 5)));
  Printf.printf("%d %d\n", x, y);
};
