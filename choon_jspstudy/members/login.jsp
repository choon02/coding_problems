<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%--
	로그인 폼 만들기
	loginCheck.jsp로 전송하기
 --%>
	<h2>로그인</h2>
	<form action="loginCheck.jsp" method="post">
		아이디: <input type="text" name="id" size="10"><br>
		비밀번호: <input type="password" name="pw" size="20"><br>
		
		<input type="button" value="회원가입" onclick="javascript:window.location='join.jsp'">
		&nbsp;&nbsp;&nbsp;
		<input type="submit" value="로그인">
	</form>
</body>
</html>