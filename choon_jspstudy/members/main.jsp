<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
<%
	// key값인 id 받기, 이름 출력하기 위해 이름 받기
	if(session.getAttribute("id") == null || session.getAttribute("name") == null ){    
		response.sendRedirect("login.jsp");
	}
	String name = (String)session.getAttribute("name");
	String id = (String)session.getAttribute("id");
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<h1><%=name %>님 안녕하세요~~</h1>
	<button onclick="javascript:window.location='logout.jsp'">로그아웃</button>
	&nbsp;&nbsp;&nbsp;
	<button onclick="javascript:window.location='modify.jsp'">나의 정보수정</button>
	&nbsp;&nbsp;&nbsp;
	<button onclick="javascript:window.location='delete.jsp'">회원탈퇴</button>
	</body>
</html>