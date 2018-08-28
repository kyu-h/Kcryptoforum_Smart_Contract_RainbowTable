<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Page Title</title>
    <script type=”text/javascript” src=”web3.min.js”></script>
    <script type=”text/javascript” src=”eth.js”></script>
    <script src="https://cdn.jsdelivr.net/gh/ethereum/web3.js/dist/web3.min.js"></script>
    <script src="http://code.jquery.com/jquery-1.10.2.js"></script> <!-- jquery 사용하고 싶을 경우  import -->
</head>
<style>
    table, th, td {
        border: 1px solid black;
    }
</style>
<body>
    <p>Please click algorithm type and output bits.</p>
    <script>
        var cookie = document.cookie;
        var split_cookie = cookie.split('/');
        
        var algo = split_cookie[0];
        var bits = split_cookie[1];
        var input_text = split_cookie[2];
        
        if(split_cookie[3] != null){
            var config = split_cookie[3];
        }
        
        console.log(cookie);
        console.log(input_text);
    </script>
</body>
</html>
