<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="aaa.com.TxtRead" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<style>
body {
  width: 480px;
  margin: 0 auto;
}
</style>
<title>aaa</title>
</head>

<body>

<h1>aaa MiniProject2!! </h1>
<section>
	<h3>Menu</h3>
		<jsp:include page="aaaMenu.jsp"></jsp:include>
</section>

<!--  <section>
	<h3>'Box Office Rank' Search Results</h3>
		<jsp:include page="dongaMovieList.jsp"></jsp:include>
</section>-->

<% TxtRead tr = new TxtRead(); %>
<% tr.main(new String[] {"some", "arguments"}); %>

</body>
</html>