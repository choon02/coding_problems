<%@page import="com.jsp.members.MembersDAO"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
		request.setCharacterEncoding("UTF-8");
	%>
	
	<jsp:useBean id="dto" class="com.jsp.members.MembersDTO"/>
	<jsp:setProperty property="*" name="dto"/>
	
	<%
		MembersDAO dao = MembersDAO.getInstance();
		int result = dao.updateMember(dto);
		if(result == 1){
	%>
		<script>
			alert('회원정보가 수정되었습니다.');
			window.location ='main.jsp';
		</script>
	<%
		}else{	
	%>
		<script>
			alert('회원정보 수정 실패입니다.');
			history.back();
		</script>
	<%
		}
	%>
</body>
</html>