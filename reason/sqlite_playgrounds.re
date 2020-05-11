open Core;
open Sqlite3;

let find_index = (~predicate, arr) => {
  let (index, _) =
    Array.findi_exn(~f=(index, value) => predicate(value), arr);
  index;
};

type row = array(string);
type column_name = string;
type db_result = (array(column_name), array(row));

let get_rows = (db, query_string): db_result => {
  let result = ref([||]);
  let header = ref([||]);
  ignore @@
  Sqlite3.exec_not_null(
    db,
    (row, header_) => {
      header := header_;
      result := Array.append(result^, [|row|]);
    },
    query_string,
  );
  (header^, result^);
};

let get_values_by_column = (result: db_result, column) => {
  let (header, values) = result;
  let index = find_index(~predicate=v => String.equal(v, column), header);
  Array.map(~f=v => v[index], values);
};

let array_to_string = arr =>
  Array.fold(~f=(acc, s) => acc ++ "," ++ s, ~init="", arr) ++ "\n";

let () = {
  let google_chrome_search_provider = "/Users/kanenobu/Library/Application Support/Google/Chrome/Default/Web Data";

  let db = Sqlite3.db_open(google_chrome_search_provider);
  let result = get_rows(db, "SELECT * FROM keywords");
  ignore @@ Sqlite3.db_close(db);
  let (header, values) = result;
  print_endline("Headers");
  header |> Array.iter(~f=h => printf("%s, ", h));
  printf("\n");
  print_endline("Values");
  values |> Array.iter(~f=h => printf("%s, ") @@ array_to_string(h));
  printf("\n");
  Array.iter(~f=v => printf("%s, ", v), get_values_by_column(result, "id"));
};
