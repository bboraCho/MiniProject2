<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Movie url</title>
<style>
body {
  width: 400px;
  margin: 0 auto;
}

.box {
                border-color: mediumpurple;
                border-width: 20px;
                border-style: solid;
                padding: 30px 30px;
                margin: 0 auto;   
                width: 300px;            
        }
</style>
</head>
<body>
<section>
	<h3>'Box Office Rank' Search Results</h3>
		<jsp:include page="dongaMovieList.jsp"></jsp:include>
</section>
</body>
</html>