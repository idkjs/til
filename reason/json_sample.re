open Core;
module Json = Yojson.Basic;

let ordinary_json = () => {
  let json = Json.from_file("./json_sample.json");
  printf("%s\n") @@ Json.to_string(json);
};

[@deriving show]
type json2 = {key: string};

let array_json = () => {
  let parse = (json: list(Json.t)): list(json2) =>
    json
    |> List.map(~f=j => {key: Json.Util.member("key", j) |> Json.to_string});

  let json = Json.from_file("./json_sample_array.json");
  let listed = Json.Util.to_list(json);
  listed |> parse |> List.iter(~f=node => print_endline(show_json2(node)));
};

let () = {
  ordinary_json();
  array_json();
};
