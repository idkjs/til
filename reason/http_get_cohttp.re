/* client_example.ml */
open Lwt;
open Cohttp;

/* open Cohttp_lwt_unix */

let get = url =>
  Client.get(Uri.of_string(url))
  >>= (
    ((resp, body)) => {
      let code = resp |> Response.status |> Code.code_of_status;
      let res_body = body |> Cohttp_lwt.Body.to_string;
      res_body;
    }
  );

let () = {
  let body = Lwt_main.run @@ get("https://www.reddit.com/");
  print_endline("Received body\n" ++ body);
};
