open Printf;

let rec read_lines = ic =>
  try({
    let line = input_line(ic);
    [line, ...read_lines(ic)];
  }) {
  | End_of_file => []
  };

let split_line = line => Str.split(Str.regexp("[ \t]+"), line);

let () = {
  let lines = read_lines(stdin);
  List.iter(e => printf("%s;;", e), lines);
};
