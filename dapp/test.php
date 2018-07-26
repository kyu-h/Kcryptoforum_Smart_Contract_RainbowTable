<!DOCTYPE html>

<?php
// Create connection
$con=mysqli_connect("localhost","root", "123123", "check");

// Check connection
if (mysqli_connect_errno()){
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
}else {
    echo "success to access";
    echo "<br>";
}
$result = mysqli_query($con, "SELECT * FROM Node");

?>
<html>
<head>
    <meta charset="UTF-8">
    <title>Page Title</title>
    <script type=”text/javascript” src=”web3.min.js”></script>
    <script type=”text/javascript” src=”eth.js”></script>
    <script src="https://cdn.jsdelivr.net/gh/ethereum/web3.js/dist/web3.min.js"></script>
    <script>
        if (typeof web3 !== 'undefined') {
          web3 = new Web3(web3.currentProvider);
        } else {
          // set the provider you want from Web3.providers
          web3 = new Web3(new Web3.providers.HttpProvider("http://localhost:8545"));
        }
        
        var network_version = web3.version.network;
        console.log(network_version);
        
        var accounts = web3.eth.accounts;  //get account info
        var from_account = accounts[0];
        var to_account = accounts[1];
        
        var coinbase = web3.eth.coinbase;
        var balance = web3.fromWei(web3.eth.getBalance(coinbase), 'ether');
        
        console.log(coinbase);
        console.log(balance.c); //check ether in the coinbase 
        
        console.log(from_account);
        console.log(to_account);
        
        var transactionObj = { //transaction object setting
            from: from_account,
            to:to_account,
            value: 10000000
        };
        
        </script>
        <?
            while($row = mysqli_fetch_array($result)){
                echo $row['id'] . " " . $row['degree'];
                echo "<br>";

                if ($row[0] == '3'){
                    $str = '1';
                    echo "degree is over 23";
                }
            }
        ?>
        <script>
            var str = '<?= $str ?>';
            if(str == '1'){
                web3.eth.sendTransaction(transactionObj)        
            }
        </script>
</head>
<body>

    <h1>This is a HeadidddngGGG</h1>
    <p>This is a paragraph.</p>

</body>
</html>
