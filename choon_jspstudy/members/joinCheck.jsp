<%@page import="com.jsp.members.MembersDTO"%>
<%@page import="com.jsp.members.MembersDAO"%>
<%@page import="java.sql.Timestamp"%>
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
		1. 넘어온 데이터 받기
		2. 현재시간으로 Timestamp 객체 생성하기
		3. DTO 객체에 넘어온데이터와 Timestap 셋팅하기
		4. DAO 객체 생성 후 confirmId 메소드 호출해서 같은 아이디가 없다면
		insertMember 메소드 호출하여 DB에 데이터 넣기
		
	 --%>
	  <%
	 	request.setCharacterEncoding("UTF-8");
	  %>
	  <jsp:useBean id="dto" class="com.jsp.members.MembersDTO"/>
	  <jsp:setProperty property="*" name="dto"/>
	  
	  <%--
	  	form에서 넘어오는 파라미터가 많을 경우 property 속성값을 *로 주면
	  	넘어오는 데이터들이 property 값으로 세팅된다.
	  	주의할 점은 폼으로부터 넘어오는 파라미터의 이름과 프로퍼티의 이름이 일치해야 한다.
	  --%>
	  <%
	  	dto.setRegDate(new Timestamp(System.currentTimeMillis()));
	  //regDate까지 DTO 객체에 세팅해준다.
	    MembersDAO dao = MembersDAO.getInstance();
	  	if(dao.confirmId(dto.getId()) == 1){//같은 아이디가 있을 때
	  %>
	  	<script type="text/javascript">
	  		alert('아이디가 이미 존재합니다.');
	  		history.back(); // 이전페이지로 이동
	  	</script>
	  <%
	  	}else{//같은 아이디가 없다면 회원가입 OK
	  		int result = dao.insertMember(dto);
	  		if(result == 1){		
	  %>
	  	<script>
	  		alert('회원가입을 축하합니다');
	  		window.location='login.jsp'
	  	</script>
	  <%
	  		}
	  		else{ 
	  %>
	  		<script>
	  			alert('회원가입에 실패했습니다');
	  			window.location = 'join.jsp';
	  		</script>			
	  <%
	  		}
	  	}
	  %>
</body>
</html>