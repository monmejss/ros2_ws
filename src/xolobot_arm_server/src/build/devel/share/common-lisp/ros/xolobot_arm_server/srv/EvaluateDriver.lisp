; Auto-generated. Do not edit!


(cl:in-package xolobot_arm_server-srv)


;//! \htmlinclude EvaluateDriver-request.msg.html

(cl:defclass <EvaluateDriver-request> (roslisp-msg-protocol:ros-message)
  ((weightsfile
    :reader weightsfile
    :initarg :weightsfile
    :type cl:string
    :initform "")
   (maxtime
    :reader maxtime
    :initarg :maxtime
    :type cl:integer
    :initform 0)
   (touchthreshold
    :reader touchthreshold
    :initarg :touchthreshold
    :type cl:float
    :initform 0.0))
)

(cl:defclass EvaluateDriver-request (<EvaluateDriver-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <EvaluateDriver-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'EvaluateDriver-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name xolobot_arm_server-srv:<EvaluateDriver-request> is deprecated: use xolobot_arm_server-srv:EvaluateDriver-request instead.")))

(cl:ensure-generic-function 'weightsfile-val :lambda-list '(m))
(cl:defmethod weightsfile-val ((m <EvaluateDriver-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xolobot_arm_server-srv:weightsfile-val is deprecated.  Use xolobot_arm_server-srv:weightsfile instead.")
  (weightsfile m))

(cl:ensure-generic-function 'maxtime-val :lambda-list '(m))
(cl:defmethod maxtime-val ((m <EvaluateDriver-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xolobot_arm_server-srv:maxtime-val is deprecated.  Use xolobot_arm_server-srv:maxtime instead.")
  (maxtime m))

(cl:ensure-generic-function 'touchthreshold-val :lambda-list '(m))
(cl:defmethod touchthreshold-val ((m <EvaluateDriver-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xolobot_arm_server-srv:touchthreshold-val is deprecated.  Use xolobot_arm_server-srv:touchthreshold instead.")
  (touchthreshold m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <EvaluateDriver-request>) ostream)
  "Serializes a message object of type '<EvaluateDriver-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'weightsfile))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'weightsfile))
  (cl:let* ((signed (cl:slot-value msg 'maxtime)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'touchthreshold))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <EvaluateDriver-request>) istream)
  "Deserializes a message object of type '<EvaluateDriver-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'weightsfile) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'weightsfile) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'maxtime) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'touchthreshold) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<EvaluateDriver-request>)))
  "Returns string type for a service object of type '<EvaluateDriver-request>"
  "xolobot_arm_server/EvaluateDriverRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EvaluateDriver-request)))
  "Returns string type for a service object of type 'EvaluateDriver-request"
  "xolobot_arm_server/EvaluateDriverRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<EvaluateDriver-request>)))
  "Returns md5sum for a message object of type '<EvaluateDriver-request>"
  "6abca6379b4838beaac4cbca82c88812")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'EvaluateDriver-request)))
  "Returns md5sum for a message object of type 'EvaluateDriver-request"
  "6abca6379b4838beaac4cbca82c88812")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<EvaluateDriver-request>)))
  "Returns full string definition for message of type '<EvaluateDriver-request>"
  (cl:format cl:nil "string weightsfile~%int64 maxtime~%float64 touchthreshold~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'EvaluateDriver-request)))
  "Returns full string definition for message of type 'EvaluateDriver-request"
  (cl:format cl:nil "string weightsfile~%int64 maxtime~%float64 touchthreshold~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <EvaluateDriver-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'weightsfile))
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <EvaluateDriver-request>))
  "Converts a ROS message object to a list"
  (cl:list 'EvaluateDriver-request
    (cl:cons ':weightsfile (weightsfile msg))
    (cl:cons ':maxtime (maxtime msg))
    (cl:cons ':touchthreshold (touchthreshold msg))
))
;//! \htmlinclude EvaluateDriver-response.msg.html

(cl:defclass <EvaluateDriver-response> (roslisp-msg-protocol:ros-message)
  ((time
    :reader time
    :initarg :time
    :type cl:float
    :initform 0.0)
   (dist2go
    :reader dist2go
    :initarg :dist2go
    :type cl:float
    :initform 0.0)
   (damage
    :reader damage
    :initarg :damage
    :type cl:float
    :initform 0.0)
   (energy
    :reader energy
    :initarg :energy
    :type cl:float
    :initform 0.0)
   (velocity
    :reader velocity
    :initarg :velocity
    :type cl:float
    :initform 0.0)
   (crashRisk
    :reader crashRisk
    :initarg :crashRisk
    :type cl:float
    :initform 0.0))
)

(cl:defclass EvaluateDriver-response (<EvaluateDriver-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <EvaluateDriver-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'EvaluateDriver-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name xolobot_arm_server-srv:<EvaluateDriver-response> is deprecated: use xolobot_arm_server-srv:EvaluateDriver-response instead.")))

(cl:ensure-generic-function 'time-val :lambda-list '(m))
(cl:defmethod time-val ((m <EvaluateDriver-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xolobot_arm_server-srv:time-val is deprecated.  Use xolobot_arm_server-srv:time instead.")
  (time m))

(cl:ensure-generic-function 'dist2go-val :lambda-list '(m))
(cl:defmethod dist2go-val ((m <EvaluateDriver-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xolobot_arm_server-srv:dist2go-val is deprecated.  Use xolobot_arm_server-srv:dist2go instead.")
  (dist2go m))

(cl:ensure-generic-function 'damage-val :lambda-list '(m))
(cl:defmethod damage-val ((m <EvaluateDriver-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xolobot_arm_server-srv:damage-val is deprecated.  Use xolobot_arm_server-srv:damage instead.")
  (damage m))

(cl:ensure-generic-function 'energy-val :lambda-list '(m))
(cl:defmethod energy-val ((m <EvaluateDriver-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xolobot_arm_server-srv:energy-val is deprecated.  Use xolobot_arm_server-srv:energy instead.")
  (energy m))

(cl:ensure-generic-function 'velocity-val :lambda-list '(m))
(cl:defmethod velocity-val ((m <EvaluateDriver-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xolobot_arm_server-srv:velocity-val is deprecated.  Use xolobot_arm_server-srv:velocity instead.")
  (velocity m))

(cl:ensure-generic-function 'crashRisk-val :lambda-list '(m))
(cl:defmethod crashRisk-val ((m <EvaluateDriver-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xolobot_arm_server-srv:crashRisk-val is deprecated.  Use xolobot_arm_server-srv:crashRisk instead.")
  (crashRisk m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <EvaluateDriver-response>) ostream)
  "Serializes a message object of type '<EvaluateDriver-response>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'time))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'dist2go))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'damage))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'energy))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'velocity))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'crashRisk))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <EvaluateDriver-response>) istream)
  "Deserializes a message object of type '<EvaluateDriver-response>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'time) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'dist2go) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'damage) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'energy) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'velocity) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'crashRisk) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<EvaluateDriver-response>)))
  "Returns string type for a service object of type '<EvaluateDriver-response>"
  "xolobot_arm_server/EvaluateDriverResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EvaluateDriver-response)))
  "Returns string type for a service object of type 'EvaluateDriver-response"
  "xolobot_arm_server/EvaluateDriverResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<EvaluateDriver-response>)))
  "Returns md5sum for a message object of type '<EvaluateDriver-response>"
  "6abca6379b4838beaac4cbca82c88812")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'EvaluateDriver-response)))
  "Returns md5sum for a message object of type 'EvaluateDriver-response"
  "6abca6379b4838beaac4cbca82c88812")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<EvaluateDriver-response>)))
  "Returns full string definition for message of type '<EvaluateDriver-response>"
  (cl:format cl:nil "float64 time~%float64 dist2go~%float64 damage~%float64 energy~%float64 velocity~%float64 crashRisk~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'EvaluateDriver-response)))
  "Returns full string definition for message of type 'EvaluateDriver-response"
  (cl:format cl:nil "float64 time~%float64 dist2go~%float64 damage~%float64 energy~%float64 velocity~%float64 crashRisk~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <EvaluateDriver-response>))
  (cl:+ 0
     8
     8
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <EvaluateDriver-response>))
  "Converts a ROS message object to a list"
  (cl:list 'EvaluateDriver-response
    (cl:cons ':time (time msg))
    (cl:cons ':dist2go (dist2go msg))
    (cl:cons ':damage (damage msg))
    (cl:cons ':energy (energy msg))
    (cl:cons ':velocity (velocity msg))
    (cl:cons ':crashRisk (crashRisk msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'EvaluateDriver)))
  'EvaluateDriver-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'EvaluateDriver)))
  'EvaluateDriver-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EvaluateDriver)))
  "Returns string type for a service object of type '<EvaluateDriver>"
  "xolobot_arm_server/EvaluateDriver")